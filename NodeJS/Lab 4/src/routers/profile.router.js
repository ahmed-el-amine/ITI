import express from "express";
import useZod from "../middleware/useZod.js";
import useAuth from "../middleware/useAuth.js";
import Profiles from "../database/modules/profiles.module.js";
import { createProfilesValidationSchema } from "../lib/zod/schema/profiles.zod.js";

const router = express.Router();

router.get("/", useAuth(["user"]), async (req, res) => {
  const employees = await Profiles.find({ employeeID: req.userID }).select("firstName lastName age dateOfBirth");
  res.json({
    error: false,
    message: null,
    data: employees,
  });
});

router.post("/", useAuth(["user"]), useZod(createProfilesValidationSchema), async (req, res) => {
  // first check if profile already exist
  const isExist = await Profiles.findOne({ employeeID: req.userID });
  if (isExist) return res.status(400).json({ error: true, message: "you alrady have a profile" });

  // then create new profile if not have
  const profile = await Profiles.create(req.body);

  res.status(201).json({
    error: false,
    message: "Profile created successfully",
    data: profile,
  });
});

export default router;
