import { Body, Controller, Delete, Get, Patch, Post } from '@nestjs/common';
import { Status, Todo, TodoService } from './todo.service';

@Controller('todo')
export class TodoController {
  constructor(private readonly todoService: TodoService) {}

  @Get()
  getAllTodos(): Todo[] {
    return this.todoService.getAllTodos();
  }

  @Post()
  createTodo(@Body('task') task: string): Todo {
    return this.todoService.createTodo(task);
  }

  @Delete()
  deleteTodo(@Body('id') id: string): Todo {
    return this.todoService.deleteTodo(id);
  }

  @Patch()
  updateTodo(
    @Body('id') id: string,
    @Body('task') task: string,
    @Body('status') status: Status,
  ): Todo {
    return this.todoService.updateTodo(id, task, status);
  }
}
