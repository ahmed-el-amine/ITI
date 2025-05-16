"use client";
import React from "react";

const SearchComponent = () => {
  return (
    <div>
      <h1 className="text-2xl font-bold mb-4">Search Posts</h1>
      <input type="text" placeholder="Search..." className="border border-gray-300 rounded-lg p-2 w-full mb-4" />
      {/* button search */}
      <button className="bg-blue-500 text-white rounded-lg px-4 py-2 hover:bg-blue-600">Search</button>
    </div>
  );
};

export default SearchComponent;
