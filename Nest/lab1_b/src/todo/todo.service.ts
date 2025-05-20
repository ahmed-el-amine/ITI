import { Injectable, NotFoundException } from '@nestjs/common';
import { randomUUID } from 'crypto';

export enum Status {
  todo = 'todo',
  inProgress = 'inProgress',
  done = 'done',
}

export interface Todo {
  id: string;
  task: string;
  status: Status;
}

@Injectable()
export class TodoService {
  private todos: Todo[] = [];
  public getAllTodos() {
    return this.todos;
  }

  createTodo(task: string): Todo {
    const todo: Todo = {
      id: randomUUID(),
      task: task,
      status: Status.todo,
    };

    this.todos.push(todo);

    return todo;
  }

  deleteTodo(id: string): Todo {
    const index = this.todos.findIndex((todo) => todo.id === id);

    if (index < 0) throw new NotFoundException('Todo not found');

    const todo = this.todos[index];

    this.todos.splice(index, 1);
    return todo;
  }

  updateTodo(id: string, task: string, status: Status): Todo {
    const index = this.todos.findIndex((todo) => todo.id === id);

    if (index < 0) throw new NotFoundException('Todo not found');

    const todo = this.todos[index];

    if (task) todo.task = task;
    if (status && status in Status) {
      todo.status = status;
    }

    return todo;
  }
}
