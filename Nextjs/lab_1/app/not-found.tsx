import React from "react";

const NotFoundPage = () => {
  return (
    <div>
      <h1 className="text-3xl font-bold">404 - Page Not Found</h1>
      <p className="mt-4">Sorry, the page you are looking for does not exist.</p>
      <a href="/" className="text-blue-500 hover:underline mt-2 block">
        Go back to home
      </a>
    </div>
  );
};

export default NotFoundPage;
