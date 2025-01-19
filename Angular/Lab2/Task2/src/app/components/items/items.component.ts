import { Component, EventEmitter, Input, Output } from '@angular/core';
import { Task } from '../interfaces/task';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-items',
  imports: [FormsModule],
  templateUrl: './items.component.html',
  styleUrl: './items.component.css',
})
export class ItemsComponent {
  @Input() item!: Task;
  @Output() removeEvent = new EventEmitter<string>();

  remove() {
    this.removeEvent.emit(this.item.id);
  }
}
