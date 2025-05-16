"use client";

import React, { useActionState } from "react";
import { search } from "./search";
import { Post } from "@/types/Posts.type";

const initialState = {
  posts: [],
};

const Search = () => {
  const [state, formAction, pending] = useActionState(search, initialState);
  console.log(pending, state);

  return (
    <div>
      <form action={formAction}>
        <h1 className="text-2xl font-bold mb-4">Search Posts</h1>
        <input type="text" name="search" placeholder="Search..." className="border border-gray-300 rounded-lg p-2 w-full mb-4" />
        {/* button search */}
        <button className="bg-blue-500 text-white rounded-lg px-4 py-2 hover:bg-blue-600">Search</button>

        {pending && <p className="text-gray-500">Loading...</p>}

        {state.posts.length > 0 ? (
          <div className="mt-4">
            {state.posts.map((post: Post) => {
              return (
                <div key={Math.random()} className="border border-solid border-black/[.08] dark:border-white/[.145] rounded-lg p-4 mb-4">
                  <h2 className="text-lg font-bold">{post.title}</h2>
                  <p className="text-sm text-gray-600">{post.body}</p>
                </div>
              );
            })}
          </div>
        ) : (
          <p className="text-gray-500">No posts found</p>
        )}
      </form>
    </div>
  );
};

export default Search;
