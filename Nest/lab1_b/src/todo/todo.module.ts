import {
  MiddlewareConsumer,
  Module,
  NestModule,
  RequestMethod,
} from '@nestjs/common';
import { TodoService } from './todo.service';
import { TodoController } from './todo.controller';
import { LogCreateTodoMiddleware } from './middleware/log-create-todo.middleware';

@Module({
  controllers: [TodoController],
  providers: [TodoService],
  exports: [TodoService],
})
export class TodoModule implements NestModule {
  configure(consumer: MiddlewareConsumer) {
    consumer
      .apply(LogCreateTodoMiddleware)
      .forRoutes({ path: 'todo', method: RequestMethod.POST });
  }
}
