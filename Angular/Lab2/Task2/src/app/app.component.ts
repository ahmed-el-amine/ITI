import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { InputComponent } from './components/input/input.component';
import { ItemsListComponent } from './components/items-list/items-list.component';
import { Task } from './components/interfaces/task';

@Component({
  selector: 'app-root',
  imports: [InputComponent, ItemsListComponent, FormsModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css',
})
export class AppComponent {
  tasks: Task[] = [];

  addTask(task: string) {
    this.tasks.push({
      id: crypto.randomUUID(),
      title: task,
      isCompleted: false,
    });
  }

  removeTask(id: string) {
    this.tasks = this.tasks.filter((task) => task.id !== id);
  }
}
