package MyPackage;

public interface MyInterface {
    public int age = 0;
    default int defaultFunWithImplementation()
    {
        return 10;
    }    
}