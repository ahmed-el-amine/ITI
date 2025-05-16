import { useState } from "react";
import Reset from "./components/Reset";
import ListItems from "./components/ListItems";
import MainLayout from "../Layout/Main.Layout";

const data = [
  {
    id: 1,
    name: "test",
    count: 1,
  },
  {
    id: 2,
    name: "test2",
    count: 2,
  },
  {
    id: 3,
    name: "test3",
    count: 3,
  },
];

function App() {
  const [items, setItems] = useState(data);

  return (
    <MainLayout>
      <ul>
        <ListItems items={items} setItems={setItems} />
        <Reset data={data} setItems={setItems} />
      </ul>
      {}
    </MainLayout>
  );
}

export default App;
