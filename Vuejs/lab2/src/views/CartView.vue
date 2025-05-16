<script setup>
import { computed } from 'vue'
import { useProductStore } from '../stores/products'

const store = useProductStore()

const total = computed(() => {
  return store.cart.reduce((sum, item) => sum + (item.price * item.quantity), 0)
})
</script>

<template>
  <div class="container py-5">
    <h1 class="mb-4">Shopping Cart</h1>

    <div v-if="store.cart.length === 0" class="alert alert-info">
      Your cart is empty
    </div>

    <div v-else>
      <div class="table-responsive">
        <table class="table">
          <thead>
            <tr>
              <th>Product</th>
              <th>Price</th>
              <th>Quantity</th>
              <th>Total</th>
              <th>Action</th>
            </tr>
          </thead>
          <tbody>
            <tr v-for="item in store.cart" :key="item.id">
              <td>{{ item.title }}</td>
              <td>${{ item.price }}</td>
              <td>
                <div class="btn-group">
                  <button class="btn btn-outline-secondary btn-sm" 
                          @click="store.decrementQuantity(item.id)"
                          :disabled="item.quantity <= 1">
                    <i class="bi bi-dash"></i>
                  </button>
                  <span class="btn btn-outline-secondary btn-sm disabled">
                    {{ item.quantity }}
                  </span>
                  <button class="btn btn-outline-secondary btn-sm" 
                          @click="store.incrementQuantity(item.id)">
                    <i class="bi bi-plus"></i>
                  </button>
                </div>
              </td>
              <td>${{ item.price * item.quantity }}</td>
              <td>
                <button class="btn btn-danger btn-sm" @click="store.removeFromCart(item.id)">
                  Remove
                </button>
              </td>
            </tr>
          </tbody>
          <tfoot>
            <tr>
              <td colspan="3" class="text-end"><strong>Total:</strong></td>
              <td colspan="2"><strong>${{ total }}</strong></td>
            </tr>
          </tfoot>
        </table>
      </div>
    </div>
  </div>
</template>