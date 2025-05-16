import React from "react";

const Navbar = () => {
  return (
    <div>
      <nav className="bg-gray-800 p-4">
        <div className="container mx-auto flex justify-between items-center">
          <div className="text-white text-lg font-bold">My Blog</div>
          <ul className="flex space-x-4">
            <li>
              <a href="/" className="text-white hover:text-gray-400">
                Home
              </a>
            </li>
            <li>
              <a href="/posts/server" className="text-white hover:text-gray-400">
                Posts Server
              </a>
            </li>
            <li>
              <a href="/posts/client" className="text-white hover:text-gray-400">
                Posts Client
              </a>
            </li>
            <li>
              <a href="/posts/search" className="text-white hover:text-gray-400">
                Search
              </a>
            </li>
          </ul>
        </div>
      </nav>
    </div>
  );
};

export default Navbar;
