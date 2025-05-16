import React from "react";

interface Props {
  params: Promise<{ id: string }>;
}

const Page = async (props: Props) => {
  const { id } = await props.params;

  const res = await fetch(`https://jsonplaceholder.typicode.com/posts/${id}`, {
    cache: "no-store",
  });
  if (!res.ok) {
    throw new Error("Failed to fetch data");
  }
  const post = await res.json();

  return (
    <div key={Math.random()} className="border border-solid border-black/[.08] dark:border-white/[.145] rounded-lg p-4 mb-4">
      <h2 className="text-lg font-bold">{post.title}</h2>
      <p className="text-sm text-gray-600">{post.body}</p>
    </div>
  );
};

export default Page;
