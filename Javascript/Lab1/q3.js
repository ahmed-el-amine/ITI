const myMovies = ["Mov1", "Mov2", "Mov3", "Mov4"];

let newArray = [];

// ---------------------------------------------------
// a- copy the array into a different variable
// we can copy the array using JSON.parse like this
newArray = JSON.parse(JSON.stringify(myMovies));
myMovies[0] = "adasd";
console.log(myMovies);
console.log(newArray);

// or loop throw old array and copy to new array;
newArray = myMovies.map((x) => x);
myMovies[0] = "adasd";
console.log(myMovies);
console.log(newArray);

// ---------------------------------------------------

// b- replace the third element with a different movie
myMovies[2] = "New Mov3";
console.log(myMovies);
// ---------------------------------------------------

// c- return the last array item in 3 different ways
console.log(myMovies[myMovies.length - 1]);
console.log(myMovies.at(myMovies.length - 1));
console.log(myMovies.slice(-1)[0]);
console.log(myMovies.pop()); // mutate the original array and remove last element
// ---------------------------------------------------

// d- add a new movie to the beggining
console.log(myMovies.unshift("New Mov at beggining"));
console.log(myMovies);

// structuredClone()
