import React from "react";

const ListItems = ({ items, setItems }) => {
  const add = (id) => {
    const newItems = items.map((item) => {
      if (item.id === id) {
        return { ...item, count: item.count + 1 };
      }
      return item;
    });
    setItems(newItems);
  };

  const remove = (id) => {
    const newItems = items.map((item) => {
      if (item.id === id) {
        return { ...item, count: item.count - 1 };
      }
      return item;
    });
    setItems(newItems);
  };

  return items.map((item) => (
    <li key={item.id}>
      {item.name} - {item.count} -{" "}
      <button className="btn btn-primary" onClick={() => add(item.id)}>
        +
      </button>
      <button className="btn btn-secondary" onClick={() => remove(item.id)}>
        -
      </button>
    </li>
  ));
};

export default ListItems;
