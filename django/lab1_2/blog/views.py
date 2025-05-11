from django.shortcuts import render, get_object_or_404
from .models import Post, Author, Comment

def post_list(request):
    posts = Post.objects.all().order_by('-created_at')
    return render(request, 'blog/post_list.html', {'posts': posts})

def post_detail(request, slug):
    post = get_object_or_404(Post, slug=slug)
    comments = post.comments.all().order_by('-created_at')
    return render(request, 'blog/post_detail.html', {'post': post, 'comments': comments})

def author_profile(request, pk):
    author = get_object_or_404(Author, pk=pk)
    posts = author.posts.all().order_by('-created_at')
    post_count = posts.count()
    return render(request, 'blog/author_profile.html', {
        'author': author,
        'posts': posts,
        'post_count': post_count
    })
