import { ref } from 'vue'
import { defineStore } from 'pinia'
import axios from 'axios'

export const useProductStore = defineStore('products', () => {
  const products = ref([])
  const loading = ref(false)
  const error = ref(null)
  const cart = ref([])

  async function fetchProducts() {
    try {
      loading.value = true
      const response = await axios.get('https://api.escuelajs.co/api/v1/products')
      products.value = response.data
    } catch (err) {
      error.value = err.message
    } finally {
      loading.value = false
    }
  }

  function addToCart(product) {
    const existingItem = cart.value.find(item => item.id === product.id)
    if (existingItem) {
      existingItem.quantity++
    } else {
      cart.value.push({ ...product, quantity: 1 })
    }
  }

  function incrementQuantity(productId) {
    const item = cart.value.find(item => item.id === productId)
    if (item) {
      item.quantity++
    }
  }

  function decrementQuantity(productId) {
    const item = cart.value.find(item => item.id === productId)
    if (item && item.quantity > 1) {
      item.quantity--
    }
  }

  function removeFromCart(productId) {
    cart.value = cart.value.filter(item => item.id !== productId)
  }

  return { 
    products, 
    loading, 
    error, 
    cart, 
    fetchProducts, 
    addToCart, 
    removeFromCart,
    incrementQuantity,
    decrementQuantity 
  }
})