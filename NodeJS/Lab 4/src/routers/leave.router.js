import express from "express";
import useZod from "../middleware/useZod.js";
import { createLeavesValidationSchema, searchLeavesValidationSchema, updateLeavesValidationSchema } from "../lib/zod/schema/leaves.zod.js";
import mongoose from "mongoose";
import Leaves from "../database/modules/leaves.module.js";
import { z } from "zod";
import useAuth from "../middleware/useAuth.js";

const router = express.Router();

router.get(
  "/",
  /*useAuth(["user"]),*/ async (req, res) => {
    let { limit = 10, skip = 0, ...props } = req.query;

    const validLimit = z.coerce.number().positive().max(100).default(10).safeParse(limit);
    if (!validLimit.success) limit = 10;

    const validSkip = z.coerce.number().positive().default(0).safeParse(skip);
    if (!validSkip.success) skip = 0;

    const query = {
      // employeeID: req.userID,
    };

    Object.entries(props).forEach(([key, value]) => {
      const schema = searchLeavesValidationSchema.shape[key];
      if (!schema) return;

      const validValue = schema.safeParse(value);
      if (validValue.success) query[key] = value;
    });

    const leaves = await Leaves.find(query).skip(skip).limit(limit).lean();

    res.json({
      error: false,
      message: null,
      data: leaves,
    });
  }
);

router.post("/", useAuth(["user"]), useZod(createLeavesValidationSchema), async (req, res) => {
  const leaves = await Leaves.create({ ...req.body, employeeID: req.userID });

  res.status(201).json({
    error: false,
    message: "Leave created successfully",
    data: leaves,
  });
});

router.patch("/", useAuth(["user"]), useZod(updateLeavesValidationSchema), async (req, res) => {
  // first check employeeID is valid mongoose id
  const employeeID = req.userID;

  const isValidID = mongoose.Types.ObjectId.isValid(employeeID);
  if (!isValidID) return res.status(400).json({ error: true, message: "Invalid employeeID Please provide a valid Mongodb ID" });

  let leaves = await Leaves.findById(employeeID);

  if (!leaves) return res.status(404).json({ error: true, message: "Leave not found" });

  if (req.body.status && leaves.status !== "inprogress")
    return res.status(400).json({ error: true, message: `Cannot update leave status from ${leaves.status} to ${req.body.status}` });

  // update each key
  Object.keys(req.body).forEach((key) => {
    leaves[key] = req.body[key];
  });
  // save the update
  leaves = await leaves.save();

  res.json({
    error: false,
    message: "Leave updated successfully",
    data: leaves,
  });
});

export default router;
