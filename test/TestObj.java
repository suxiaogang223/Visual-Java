class TestObj{
    int add(int a,int b){
        return a+b;
    }

    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        TestObj obj = new TestObj();
        int c = obj.add(a,b);
    }
}