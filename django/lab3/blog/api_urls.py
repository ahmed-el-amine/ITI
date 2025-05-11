from django.urls import path
from . import api_views

urlpatterns = [
    # Post endpoints
    path('posts/', api_views.PostListCreate.as_view(), name='post-list-create'),
    path('posts/<int:pk>/', api_views.PostRetrieveUpdateDestroy.as_view(), name='post-detail'),
    
    # Author endpoints
    path('authors/', api_views.AuthorListCreate.as_view(), name='author-list-create'),
    path('authors/<int:pk>/', api_views.AuthorRetrieveUpdateDestroy.as_view(), name='author-detail'),
]