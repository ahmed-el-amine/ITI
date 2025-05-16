"use server";
export const search = async (prevState: any, formData: FormData) => {
  const search = formData.get("search") as string;
  const res = await fetch(`https://jsonplaceholder.typicode.com/posts?q=${search}`, {
    cache: "no-store",
  });
  if (!res.ok) {
    throw new Error("Failed to fetch data");
  }
  const data = await res.json();

  return { posts: data };
};
