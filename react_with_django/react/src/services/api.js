import axios from 'axios';

const API_URL = 'http://localhost:8000/api/';

const api = axios.create({
  baseURL: API_URL,
});

// Add token to requests if available
api.interceptors.request.use(
  (config) => {
    const token = localStorage.getItem('token');
    if (token) {
      config.headers.Authorization = `Bearer ${token}`;
    }
    return config;
  },
  (error) => Promise.reject(error)
);

export const login = async (username, password) => {
  const response = await axios.post('http://localhost:8000/api/token/', { username, password });
  return response.data;
};

export const register = async (userData) => {
  const response = await axios.post(`${API_URL}register/`, userData);
  return response.data;
};

export const getPosts = async () => {
  const response = await api.get('posts/');
  return response.data;
};

export const getPost = async (id) => {
  const response = await api.get(`posts/${id}/`);
  return response.data;
};

export const createPost = async (postData) => {
  const response = await api.post('posts/', postData);
  return response.data;
};

export const updatePost = async (id, postData) => {
  const response = await api.put(`posts/${id}/`, postData);
  return response.data;
};

export const deletePost = async (id) => {
  const response = await api.delete(`posts/${id}/`);
  return response.data;
};

export default api;