import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs';
import { Product } from '../interfaces/product.interface';

interface CartItem extends Product {
  quantity: number;
}

@Injectable({
  providedIn: 'root',
})
export class CartService {
  private cartItems = new BehaviorSubject<CartItem[]>([]);
  cartItems$ = this.cartItems.asObservable();

  constructor() {
    // Load cart from localStorage if available
    const savedCart = localStorage.getItem('cart');
    if (savedCart) {
      this.cartItems.next(JSON.parse(savedCart));
    }
  }

  addToCart(product: Product) {
    const currentItems = this.cartItems.value;
    const existingItem = currentItems.find((item) => item.id === product.id);

    let updatedItems: CartItem[];

    if (existingItem) {
      // If item exists, increase quantity
      updatedItems = currentItems.map((item) =>
        item.id === product.id ? { ...item, quantity: item.quantity + 1 } : item
      );
    } else {
      // If item doesn't exist, add it with quantity 1
      updatedItems = [...currentItems, { ...product, quantity: 1 }];
    }

    this.cartItems.next(updatedItems);
    this.saveToLocalStorage(updatedItems);
  }

  removeFromCart(productId: number) {
    const updatedItems = this.cartItems.value.filter(
      (item) => item.id !== productId
    );
    this.cartItems.next(updatedItems);
    this.saveToLocalStorage(updatedItems);
  }

  updateQuantity(productId: number, quantity: number) {
    const updatedItems = this.cartItems.value.map((item) =>
      item.id === productId ? { ...item, quantity } : item
    );
    this.cartItems.next(updatedItems);
    this.saveToLocalStorage(updatedItems);
  }

  clearCart() {
    this.cartItems.next([]);
    localStorage.removeItem('cart');
  }

  private saveToLocalStorage(items: CartItem[]) {
    localStorage.setItem('cart', JSON.stringify(items));
  }

  getTotalItems(): number {
    return this.cartItems.value.reduce(
      (total, item) => total + item.quantity,
      0
    );
  }

  getTotalPrice(): number {
    return this.cartItems.value.reduce(
      (total, item) => total + item.price * item.quantity,
      0
    );
  }
}
