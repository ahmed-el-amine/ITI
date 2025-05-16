"use client";
import { Post } from "@/types/Posts.type";
import { useCallback, useEffect, useState } from "react";

const usePosts = () => {
  const [posts, setPosts] = useState<Post[]>([]);

  const fetchPosts = useCallback(async () => {
    const res = await fetch("https://jsonplaceholder.typicode.com/posts", {});
    if (!res.ok) {
      throw new Error("Failed to fetch data");
    }
    const data = await res.json();
    setPosts(data);
  }, []);

  useEffect(() => {
    fetchPosts();
  }, []);

  return posts;
};

export default usePosts;
