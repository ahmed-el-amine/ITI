import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { BehaviorSubject, Observable } from 'rxjs';
import { Product } from '../interfaces/product.interface';

@Injectable({
  providedIn: 'root',
})
export class ProductService {
  private productsUrl = 'https://dummyjson.com/products'; // API URL for all products
  private productUrl = 'https://dummyjson.com/products'; // Base URL for single product
  private products: Product[] = [];
  private productsSubject = new BehaviorSubject<Product[]>([]);

  constructor(private http: HttpClient) {
    this.fetchProducts();
  }

  // Fetch all products from the API
  private fetchProducts(): void {
    this.http.get<{ products: Product[] }>(this.productsUrl).subscribe({
      next: (response) => {
        this.products = response.products; // Store the fetched products
        this.productsSubject.next(this.products); // Notify subscribers
      },
      error: (error) => {
        console.error('Error fetching products:', error);
      },
    });
  }

  // Get all products as an observable
  getProducts(): Observable<Product[]> {
    return this.productsSubject.asObservable();
  }

  // Get a product by ID from the API
  getProductById(id: number): Observable<Product> {
    const url = `${this.productUrl}/${id}`; // Construct the URL for the specific product
    return this.http.get<Product>(url); // Return the observable for the single product
  }
}
