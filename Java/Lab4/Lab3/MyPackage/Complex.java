package MyPackage;

public class Complex<T extends Number> {
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

    public Complex<Double> addition(Complex<T> other) {
        double newReal = (double)this.real + (double)other.real;
        Double newImg =  (double)this.img +  (double)other.img;
        return new Complex<>(newReal, newImg);
    }

    public Complex<Double> subtract(Complex<T> other) {
        Double newReal = (double)this.real -(double) other.real;
        Double newImg = (double)this.img -(double) other.img;
        return new Complex<>( newReal,  newImg);
    }
}
