import express from "express";
import emoloyessRouter from "./employees.router.js";
import leavesRouter from "./leave.router.js";
import profileRouter from "./profile.router.js";
import authRouter from "./auth.router.js";

const router = express.Router();

router.use("/auth", authRouter);
router.use("/employees", emoloyessRouter);
router.use("/leave", leavesRouter);
router.use("/profiles", profileRouter);

export default router;
