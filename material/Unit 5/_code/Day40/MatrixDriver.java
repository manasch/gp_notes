 interface Matrix {
    int get(int row, int col);
    void set(int row, int col, int value);
    Matrix add(Matrix other);
    Matrix subtract(Matrix other);
    Matrix multiply(Matrix other);
    Matrix divide(Matrix other);
    int rows();
    int cols();
}

 class ArrayImplementation implements Matrix {
    private int[][] data;
    private int rows;
    private int cols;

    public ArrayImplementation(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        data = new int[rows][cols];
    }

    public int get(int row, int col) {
        return data[row][col];
    }

    public void set(int row, int col, int value) {
        data[row][col] = value;
    }

    public Matrix add(Matrix other) {
        if (other instanceof ArrayImplementation) {
            ArrayImplementation m = (ArrayImplementation) other;
            ArrayImplementation result = new ArrayImplementation(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.set(i, j, get(i, j) + m.get(i, j));
                }
            }
            return result;
        } else {
            throw new IllegalArgumentException("Incompatible matrix types");
        }
    }

    public Matrix subtract(Matrix other) {
        if (other instanceof ArrayImplementation) {
            ArrayImplementation m = (ArrayImplementation) other;
            ArrayImplementation result = new ArrayImplementation(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.set(i, j, get(i, j) - m.get(i, j));
                }
            }
            return result;
        } else {
            throw new IllegalArgumentException("Incompatible matrix types");
        }
    }

    public Matrix multiply(Matrix other) {
        if (other instanceof ArrayImplementation) {
            ArrayImplementation m = (ArrayImplementation) other;
            if (cols != m.rows) {
                throw new IllegalArgumentException("Incompatible matrix dimensions");
            }
            ArrayImplementation result = new ArrayImplementation(rows, m.cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < m.cols; j++) {
                    int sum = 0;
                    for (int k = 0; k < cols; k++) {
                        sum += get(i, k) * m.get(k, j);
                    }
                    result.set(i, j, sum);
                }
            }
            return result;
        } else {
            throw new IllegalArgumentException("Incompatible matrix types");
        }
    }

    public Matrix divide(Matrix other) {
        throw new UnsupportedOperationException("Divide operation not supported");
    }

    public int rows() {
        return rows;
    }

    public int cols() {
        return cols;
    }
}

public class MatrixDriver {
    public static void main(String[] args) {
        ArrayImplementation a = new ArrayImplementation(2, 3);
        a.set(0, 0, 1);
        a.set(0, 1, 2);
        a.set(0, 2, 3);
        a.set(1, 0, 4);
        a.set(1, 1, 5);
        a.set(1, 2, 6);

        ArrayImplementation b = new ArrayImplementation(3, 2);
        b.set(0, 0, 7);
        b.set(0, 1, 8);
        b.set(1, 0, 9);
        b.set(1, 1, 10);
        b.set(2, 0, 11);
        b.set(2, 1, 12);

        Matrix c = a.multiply(b);
        System.out.println("a * b:");
        for (int i = 0; i < c.rows(); i++) {
            for (int j = 0; j < c.cols(); j++) {
                System.out.print(c.get(i, j) + " ");
            }
            System.out.println();
        }
    }
}

       
