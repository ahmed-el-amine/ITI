<script setup>
import { onMounted } from 'vue'
import { useProductStore } from '../stores/products'

const store = useProductStore()

onMounted(() => {
  store.fetchProducts()
})
</script>

<template>
  <div class="container py-5">
    <h1 class="mb-4">Our Products</h1>
    
    <div v-if="store.loading" class="text-center">
      <div class="spinner-border" role="status">
        <span class="visually-hidden">Loading...</span>
      </div>
    </div>

    <div v-else-if="store.error" class="alert alert-danger">
      {{ store.error }}
    </div>

    <div v-else class="row g-4">
      <div v-for="product in store.products" :key="product.id" class="col-md-4">
        <div class="card h-100">
          <img :src="product.images[0]" class="card-img-top" :alt="product.title">
          <div class="card-body">
            <h5 class="card-title">{{ product.title }}</h5>
            <p class="card-text">{{ product.description }}</p>
            <p class="card-text"><strong>Price: ${{ product.price }}</strong></p>
            <button class="btn btn-primary" @click="store.addToCart(product)">
              Add to Cart
            </button>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>