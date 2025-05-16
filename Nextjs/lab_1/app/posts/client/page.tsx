"use client";
import usePosts from "@/hooks/usePosts";
import Link from "next/link";
import React from "react";

const page = () => {
  const posts = usePosts();
  return (
    <div>
      {posts.map((post) => {
        return (
          <div key={Math.random()} className="border border-solid border-black/[.08] dark:border-white/[.145] rounded-lg p-4 mb-4">
            <h2 className="text-lg font-bold">{post.title}</h2>
            <p className="text-sm text-gray-600">{post.body}</p>
            <Link href={`/posts/${post.id}`} className="text-blue-500 hover:underline mt-2 block">
              Read more
            </Link>
          </div>
        );
      })}
    </div>
  );
};

export default page;
