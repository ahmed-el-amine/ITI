import { existsSync, mkdirSync, readFileSync, writeFileSync } from "fs";
import path from "path";

interface DBProps {
  fileName: string;
  path: string;
}

class DB {
  private fileName: string;
  private path: string;
  private fullPath: string;
  constructor(props: DBProps) {
    this.fileName = props.fileName;
    this.path = props.path;
    this.fullPath = path.join(this.path, this.fileName);
    this.createDBFolder();
    this.initialDBFile();
  }

  public getLastIndex() {
    const db = JSON.parse(readFileSync(this.fullPath, "utf-8"));
    return db.schema.lastIndex;
  }

  public updateLastIndex(index: number) {
    const db = this.readData();
    db.schema.lastIndex = index;
    this.writeData(db);
  }

  public addEmployee(data: any) {
    const db = this.readData();
    db.employees.push(data);
    this.writeData(db);
  }

  public deleteEmployee(id: string): boolean {
    let isDeleted = false;

    const db = this.readData();
    const newData = db.employees.filter((e: any) => e.id != id);

    if (newData.length < db.employees.length) isDeleted = true;

    db.employees = newData;

    this.writeData(db);

    return isDeleted;
  }

  public editEmployee(data: any) {
    let isUpdated = false;
    const db = this.readData();
    const newData = db.employees.map((e: any) => {
      if (e.id == data.id) {
        isUpdated = true;
        return { ...e, ...data, id: e.id };
      }
      return e;
    });
    db.employees = newData;
    this.writeData(db);

    return isUpdated;
  }

  public getEmployees(): { [key: string]: string }[] {
    return this.readData().employees || [];
  }

  private readData() {
    return JSON.parse(readFileSync(this.fullPath, "utf-8"));
  }

  private writeData(data: any) {
    writeFileSync(this.fullPath, JSON.stringify(data));
  }

  private createDBFolder() {
    try {
      mkdirSync(this.path, { recursive: true });
    } catch (error) {}
  }

  private initialDBFile() {
    // check if file not exist
    if (existsSync(this.fullPath)) return;
    try {
      writeFileSync(this.fullPath, JSON.stringify({ schema: { lastIndex: 0 }, employees: [] }));
    } catch (error) {}
  }

  private static Database: DB | null = null;
  static createDB(props: DBProps) {
    if (DB.Database != null) return;

    DB.Database = new DB(props);
  }

  static getDB(): DB {
    if (DB.Database == null) {
      throw new Error("DB is not created");
    }
    return DB.Database;
  }
}

export default DB;
