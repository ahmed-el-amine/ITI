import React from "react";
import MainLayout from "../../Layout/Main.Layout";

const Shuffle = () => {
  const [data] = React.useState([
    ["Egypt", "Cairo"],
    ["France", "Paris"],
    ["UK", "London"],
  ]);

  const shuffleArray = (array) => {
    for (let i = array.length - 1; i > 0; i--) {
      const j = Math.floor(Math.random() * (i + 1));

      [array[i], array[j]] = [array[j], array[i]];
    }

    return array;
  };
  return (
    <MainLayout>
      {shuffleArray(data.flat()).map((item, index) => {
        return <div key={index}>{item}</div>;
      })}
    </MainLayout>
  );
};

export default Shuffle;
