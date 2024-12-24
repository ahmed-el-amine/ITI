package MyPackage;

public class Complex<T extends Double> {
    private T real;
    private T img;

    public Complex(T real, T img)
    {
        this.real = real;
        this.img = img;
    }
    
    public void setImg(T img) {
        this.img = img;
    }

    public T getImg() {
        return img;
    }

    public void setReal(T real) {
        this.real = real;
    }

    public T getReal() {
        return real;
    }

    public void display()
    {
        if ((Double)this.real == 0 && (Double)this.img == 0)
        {
            System.out.println("0");
            return;
        }

        if ((Double)this.real != 0)
            System.out.print(this.real);
        if ((Double)this.img > 0)
            System.out.println("+" + this.img + "j");
        else if ((Double)this.img < 0)
            System.out.println(this.img + "j");
    }

    public Complex<T> addition(Complex<T> other) {
        Double newReal = this.real + other.real;
        Double newImg = this.img + other.img;
        return new Complex<>((T) newReal, (T) newImg);
    }

    public Complex<T> subtract(Complex<T> other) {
        Double newReal = this.real - other.real;
        Double newImg = this.img - other.img;
        return new Complex<>((T) newReal, (T) newImg);
    }
}
