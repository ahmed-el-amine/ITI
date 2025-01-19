import { Component, EventEmitter, Input, Output } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { ItemsComponent } from '../items/items.component';
import { Task } from '../interfaces/task';

@Component({
  selector: 'app-items-list',
  imports: [FormsModule, ItemsComponent],
  templateUrl: './items-list.component.html',
  styleUrl: './items-list.component.css',
})
export class ItemsListComponent {
  @Input() items: Task[] = [];
  @Output() removeTaskEvent = new EventEmitter<string>();

  removeTask(id: string) {
    this.removeTaskEvent.emit(id);
  }
}
