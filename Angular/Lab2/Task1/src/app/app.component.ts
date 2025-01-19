import { Component } from '@angular/core';
import { ListComponent } from './components/list/list.component';

@Component({
  selector: 'app-root',
  imports: [ListComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css',
})
export class AppComponent {}
