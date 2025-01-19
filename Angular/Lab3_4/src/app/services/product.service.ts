import { Injectable } from '@angular/core';
import { BehaviorSubject, Observable } from 'rxjs';
import { Product } from '../interfaces/product.interface';
import data from '../assets/products.json';

@Injectable({
  providedIn: 'root',
})
export class ProductService {
  private products: Product[] = data.products as any;

  getProducts(): Product[] {
    return this.products;
  }

  getProductById(id: number): Product | undefined {
    return this.products.find((product) => product.id === id);
  }
}
