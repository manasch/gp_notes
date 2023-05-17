interface CanFly {
    void fly();
}

interface CanSwim extends CanFly {
    void swim();
}

interface CanDive extends CanSwim {
    void dive();
}

class Dolphin implements CanSwim {
    @Override
    public void swim() {
        System.out.println("Swimming...");
    }

    @Override
    public void fly() {
        throw new UnsupportedOperationException("Dolphins can't fly!");
    }
}

class Whale implements CanSwim {
    @Override
    public void swim() {
        System.out.println("Swimming...");
    }

    @Override
    public void fly() {
        throw new UnsupportedOperationException("Whales can't fly!");
    }
}

class Penguin implements CanDive {
    @Override
    public void swim() {
        System.out.println("Swimming...");
    }

    @Override
    public void fly() {
        throw new UnsupportedOperationException("Penguins can't fly!");
    }

    @Override
    public void dive() {
        System.out.println("Diving...");
    }
}

public class AnimalDriver {
    public static void main(String[] args) {
        CanFly[] flyers = new CanFly[3];
        flyers[0] = new Dolphin();
        flyers[1] = new Whale();
        flyers[2] = new Penguin();

        for (CanFly flyer : flyers) {
            try {
                flyer.fly();
            } catch (UnsupportedOperationException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
