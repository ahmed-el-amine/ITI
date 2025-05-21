import { useState, useEffect, useContext } from 'react';
import { useParams, useNavigate, Link } from 'react-router-dom';
import { getPost, deletePost } from '../services/api';
import { AuthContext } from '../context/AuthContext';

function PostDetail() {
  const { id } = useParams();
  const navigate = useNavigate();
  const { user } = useContext(AuthContext);
  const [post, setPost] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const fetchPost = async () => {
      try {
        const data = await getPost(id);
        setPost(data);
      } catch (error) {
        console.error('Error fetching post:', error);
      } finally {
        setLoading(false);
      }
    };

    fetchPost();
  }, [id]);

  const handleDelete = async () => {
    if (window.confirm('Are you sure you want to delete this post?')) {
      try {
        await deletePost(id);
        navigate('/');
      } catch (error) {
        console.error('Error deleting post:', error);
      }
    }
  };

  if (loading) {
    return (
      <div className="flex justify-center items-center min-h-[50vh]">
        <div className="animate-spin rounded-full h-12 w-12 border-t-2 border-b-2 border-primary-600"></div>
      </div>
    );
  }

  if (!post) {
    return (
      <div className="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 py-8">
        <div className="bg-white rounded-lg shadow-md p-6 text-center">
          <h1 className="text-2xl font-bold text-gray-900 mb-4">Post not found</h1>
          <p className="text-gray-600 mb-4">The post you're looking for doesn't exist or has been removed.</p>
          <Link to="/" className="text-primary-600 hover:text-primary-800 font-medium">
            Return to home page
          </Link>
        </div>
      </div>
    );
  }

  const isAuthor = user && post.author === user.id;

  return (
    <div className="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 py-8">
      <div className="bg-white rounded-lg shadow-md overflow-hidden">
        <div className="p-6">
          <h1 className="text-3xl font-bold text-gray-900 mb-4">{post.title}</h1>
          <div className="text-sm text-gray-500 mb-6 pb-4 border-b border-gray-200">
            By {post.author_username} • {new Date(post.created_at).toLocaleDateString()}
          </div>
          <div className="prose max-w-none text-gray-700 mb-6 whitespace-pre-line">
            {post.content}
          </div>
          
          {isAuthor && (
            <div className="flex space-x-4 mt-8 pt-4 border-t border-gray-200">
              <Link 
                to={`/edit/${post.id}`} 
                className="px-4 py-2 bg-primary-600 text-white rounded-md hover:bg-primary-700"
              >
                Edit Post
              </Link>
              <button 
                onClick={handleDelete} 
                className="px-4 py-2 bg-red-600 text-white rounded-md hover:bg-red-700"
              >
                Delete Post
              </button>
            </div>
          )}
        </div>
      </div>
      
      <div className="mt-6">
        <Link to="/" className="text-primary-600 hover:text-primary-800 font-medium">
          ← Back to all posts
        </Link>
      </div>
    </div>
  );
}

export default PostDetail;