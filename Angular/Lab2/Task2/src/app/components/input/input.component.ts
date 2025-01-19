import { Component, EventEmitter, Output } from '@angular/core';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-input',
  imports: [FormsModule],
  templateUrl: './input.component.html',
  styleUrl: './input.component.css',
})
export class InputComponent {
  task: string = '';

  @Output() newTaskEvent = new EventEmitter<string>();

  addTask() {
    if (this.task.trim()) {
      this.newTaskEvent.emit(this.task.trim());
      this.task = '';
    }
  }
}
