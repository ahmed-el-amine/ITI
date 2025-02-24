import jwt from "jsonwebtoken";
import Employees from "../database/modules/employees.module.js";

const useAuth =
  (role = ["user"]) =>
  async (req, res, next) => {
    // read the cookie from the request
    const token = req.cookies[process.env.JWT_Cookie_Name];

    // check if token exist
    if (!token) return res.status(401).json({ error: true, message: "Unauthorized, please login" });

    // verify the token
    try {
      const { id } = jwt.verify(token, process.env.JWT_SECRET);

      const user = await Employees.findById(id);

      if (!user) return res.status(401).json({ error: true, message: "Unauthorized, please login" });

      const isRoleValid = user.roles.find((r) => role.includes(r));

      if (!isRoleValid) return res.status(403).json({ error: true, message: "Forbidden, you don't have access to this resource" });

      req.userID = id;
      next();
      // eslint-disable-next-line no-unused-vars
    } catch (error) {
      console.log(error);

      return res.status(401).json({ error: true, message: "Unauthorized, please login" });
    }
  };

export default useAuth;
