import type { Post } from "@/types/Posts.type";
import React from "react";
import Link from "next/link";

const fetchPosts = async (): Promise<Post[]> => {
  const res = await fetch("https://jsonplaceholder.typicode.com/posts", {
    cache: "no-store",
  });
  if (!res.ok) {
    throw new Error("Failed to fetch data");
  }
  return res.json();
};

const page = async () => {
  await new Promise((resolve) => setTimeout(resolve, 1500));
  const posts = await fetchPosts();

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
