package vieira.pedro.exception;

public class ConversionExcept extends RuntimeException {
    private String message;
    public ConversionExcept(String s) {
        this.message = s;
    }

    @Override
    public String getMessage() {
        return this.message;
    }
}

