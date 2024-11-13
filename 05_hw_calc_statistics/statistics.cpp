#include <iostream>
#include <limits>
#include <cmath>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
    Max() : m_max{std::numeric_limits<double>::lowest()} {}

    void update(double next) override {
        if (next > m_max) {
            m_max = next;
        }
    }

    double eval() const override {
        return m_max;
    }

    const char* name() const override {
        return "max";
    }

private:
    double m_max;
};

// среднее арифметическое
class Mean : public IStatistics {
public:
    Mean() : m_summ{0.0f}, m_counter{0} {}

    void update(double next) override {
        m_summ += next;
        ++m_counter;
    }

    double eval() const override {
        return m_counter > 0 ? m_summ / m_counter : 0.0f;
    }

    const char* name() const override {
        return "mean";
    }

private:
    double m_summ;
    size_t m_counter;
};

// среднее квадратичное
class SredKvdr : public IStatistics {
public:
    SredKvdr() : m_summa{0.0}, m_summa_squares{0.0}, m_count{0} {}

    void update(double next) override {
        m_summa += next;
        m_summa_squares += next * next;
        ++m_count;
    }

    double eval() const override {
        if (m_count < 2) {
            return 0.0f;
        }
        double mean = m_summa / m_count; // среднее арифметическое
        return std::sqrt((m_summa_squares - m_count * mean * mean) / (m_count - 1));
    }

    const char* name() const override {
        return "sr_kvd";
    }

private:
    double m_summa;
    double m_summa_squares;
    size_t m_count;
};

int main() {

	const size_t statistics_count = 4;
    IStatistics* statistics[statistics_count] = {
        new Min{},
        new Max{},
        new Mean{},
		new SredKvdr{}
    };

	statistics[0] = new Min{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}