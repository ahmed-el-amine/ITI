import mongoose from "mongoose";

const leavesSchema = new mongoose.Schema(
  {
    employeeID: {
      type: mongoose.Schema.Types.ObjectId,
      ref: "employees",
      required: true,
    },
    type: {
      type: String,
      required: true,
      enum: ["annual", "casual", "sick"],
    },
    duration: {
      type: Number,
      required: true,
    },
    status: {
      type: String,
      required: true,
      enum: ["inprogress", "cancelled", "ended"],
      default: "inprogress",
    },
  },
  {
    timestamps: true,
  }
);

const Leaves = mongoose.model("leaves", leavesSchema);

export default Leaves;
