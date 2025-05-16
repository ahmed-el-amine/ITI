<script setup>
import { RouterLink, RouterView } from "vue-router";
import { useProductStore } from "./stores/products";

const store = useProductStore();
</script>

<template>
  <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
    <div class="container">
      <RouterLink class="navbar-brand" to="/"> <i class="bi bi-shop fs-4"></i> Online Store </RouterLink>
      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav me-auto">
          <li class="nav-item">
            <RouterLink class="nav-link" to="/products">Products</RouterLink>
          </li>
        </ul>
        <RouterLink to="/cart" class="btn btn-outline-light position-relative">
          <i class="bi bi-cart3"></i> Cart
          <span v-if="store.cart.length" class="position-absolute top-0 start-100 translate-middle badge rounded-pill bg-danger">
            {{ store.cart.length }}
          </span>
        </RouterLink>
      </div>
    </div>
  </nav>

  <RouterView />
</template>

<style>
@import url("https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css");

.router-link-active {
  color: white !important;
}

.navbar {
  margin-bottom: 2rem;
}
</style>
