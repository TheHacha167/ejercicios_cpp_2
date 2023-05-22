/*
Una librer´ıa mantiene informaci´on de sus libros, clientes y ventas. Por cada libro almacena
un c´odigo, su t´ıtulo y su precio. Por cada cliente almacena un c´odigo y su
nombre. Por cada venta almacena el c´odigo del libro y el c´odigo del cliente implicados
en la venta—se supone que en una venta un cliente compra un ´ unico libro. Se
utiliza un vector para almacenar el conjunto de libros, otro vector para almacenar a los
clientes y otro vector m´as para almacenar las ventas. Dadas estas estructuras de datos
realice funciones que permitan:
(a) Dado un c´odigo de libro obtener cu´antos libros con ese c´odigo se han vendido.
(b) Dado un c´odigo de libro, obtener su posici´on en el vector de libros.
(c) Obtener el t´ıtulo del libro m´as vendido.
(d) Obtener el t´ıtulo del libro que m´as dinero ha recaudado.
(e) Dado un c´odigo de cliente obtener un vector con los t´ıtulos de los libros que ha
comprado.
(f) Obtener el nombre del cliente que ha comprado m´as libros.
(g) Obtener el nombre del cliente que ha gastado m´as dinero.
Realice un programa principal que permita probar las ´ ultimas cinco funciones.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Libro {
    int codigo;
    std::string titulo;
    double precio;
};

struct Cliente {
    int codigo;
    std::string nombre;
};

struct Venta {
    int codigoLibro;
    int codigoCliente;
};

int contarLibrosVendidos(const std::vector<Venta>& ventas, int codigoLibro) {
    int contador = 0;
    for (const auto& venta : ventas) {
        if (venta.codigoLibro == codigoLibro) {
            contador++;
        }
    }
    return contador;
}

int encontrarPosicionLibro(const std::vector<Libro>& libros, int codigoLibro) {
    for (std::size_t i = 0; i < libros.size(); ++i) {
        if (libros[i].codigo == codigoLibro) {
            return i;
        }
    }
    return -1; // Código de libro no encontrado
}

std::string obtenerTituloLibroMasVendido(const std::vector<Libro>& libros, const std::vector<Venta>& ventas) {
    int maxVentas = 0;
    int codigoLibroMasVendido = -1;

    for (const auto& libro : libros) {
        int ventasLibro = contarLibrosVendidos(ventas, libro.codigo);
        if (ventasLibro > maxVentas) {
            maxVentas = ventasLibro;
            codigoLibroMasVendido = libro.codigo;
        }
    }

    if (codigoLibroMasVendido != -1) {
        auto it = std::find_if(libros.begin(), libros.end(), [codigoLibroMasVendido](const Libro& libro) {
            return libro.codigo == codigoLibroMasVendido;
        });

        if (it != libros.end()) {
            return it->titulo;
        }
    }

    return ""; // No se encontró el libro más vendido
}

std::string obtenerTituloLibroMasDinero(const std::vector<Libro>& libros, const std::vector<Venta>& ventas) {
    double maxDinero = 0.0;
    int codigoLibroMasDinero = -1;

    for (const auto& libro : libros) {
        double dineroLibro = 0.0;
        for (const auto& venta : ventas) {
            if (venta.codigoLibro == libro.codigo) {
                dineroLibro += libro.precio;
            }
        }

        if (dineroLibro > maxDinero) {
            maxDinero = dineroLibro;
            codigoLibroMasDinero = libro.codigo;
        }
    }

    if (codigoLibroMasDinero != -1) {
        auto it = std::find_if(libros.begin(), libros.end(), [codigoLibroMasDinero](const Libro& libro) {
            return libro.codigo == codigoLibroMasDinero;
        });

        if (it != libros.end()) {
            return it->titulo;
        }
    }

    return ""; // No se encontró el libro que más dinero ha recaudado
}

std::vector<std::string> obtenerTitulosLibrosPorCliente(const std::vector<Libro>& libros, const std::vector<Venta>& ventas, int codigoCliente) {
    std::vector<std::string> titulosLibros;

    for (const auto& venta : ventas) {
        if (venta.codigoCliente == codigoCliente) {
            auto it = std::find_if(libros.begin(), libros.end(), [venta](const Libro& libro) {
                return libro.codigo == venta.codigoLibro;
            });

            if (it != libros.end()) {
                titulosLibros.push_back(it->titulo);
            }
        }
    }

    return titulosLibros;
}

std::string obtenerClienteMasCompras(const std::vector<Cliente>& clientes, const std::vector<Venta>& ventas) {
    int maxCompras = 0;
    int codigoClienteMasCompras = -1;

    for (const auto& cliente : clientes) {
        int comprasCliente = 0;
        for (const auto& venta : ventas) {
            if (venta.codigoCliente == cliente.codigo) {
                comprasCliente++;
            }
        }

        if (comprasCliente > maxCompras) {
            maxCompras = comprasCliente;
            codigoClienteMasCompras = cliente.codigo;
        }
    }

    if (codigoClienteMasCompras != -1) {
        auto it = std::find_if(clientes.begin(), clientes.end(), [codigoClienteMasCompras](const Cliente& cliente) {
            return cliente.codigo == codigoClienteMasCompras;
        });

        if (it != clientes.end()) {
            return it->nombre;
        }
    }

    return ""; // No se encontró el cliente con más compras
}

std::string obtenerClienteMasDinero(const std::vector<Cliente>& clientes, const std::vector<Libro>& libros, const std::vector<Venta>& ventas) {
    double maxDinero = 0.0;
    int codigoClienteMasDinero = -1;

    for (const auto& cliente : clientes) {
        double dineroCliente = 0.0;
        for (const auto& venta : ventas) {
            if (venta.codigoCliente == cliente.codigo) {
                auto it = std::find_if(libros.begin(), libros.end(), [venta](const Libro& libro) {
                    return libro.codigo == venta.codigoLibro;
                });

                if (it != libros.end()) {
                    dineroCliente += it->precio;
                }
            }
        }

        if (dineroCliente > maxDinero) {
            maxDinero = dineroCliente;
            codigoClienteMasDinero = cliente.codigo;
        }
    }

    if (codigoClienteMasDinero != -1) {
        auto it = std::find_if(clientes.begin(), clientes.end(), [codigoClienteMasDinero](const Cliente& cliente) {
            return cliente.codigo == codigoClienteMasDinero;
        });

        if (it != clientes.end()) {
            return it->nombre;
        }
    }

    return ""; // No se encontró el cliente que ha gastado más dinero
}

int main() {
    std::vector<Libro> libros = {
        { 1, "Libro 1", 10.99 },
        { 2, "Libro 2", 12.99 },
        { 3, "Libro 3", 9.99 }
    };

    std::vector<Cliente> clientes = {
        { 1, "Cliente 1" },
        { 2, "Cliente 2" },
        { 3, "Cliente 3" }
    };

    std::vector<Venta> ventas = {
        { 1, 1 },
        { 2, 1 },
        { 3, 2 },
        { 1, 3 }
    };

    // Prueba de las funciones
    int codigoLibroBuscado = 1;
    int librosVendidos = contarLibrosVendidos(ventas, codigoLibroBuscado);
    std::cout << "Libros vendidos con el código " << codigoLibroBuscado << ": " << librosVendidos << std::endl;

    int posicionLibro = encontrarPosicionLibro(libros, codigoLibroBuscado);
    std::cout << "Posición del libro con código " << codigoLibroBuscado << ": " << posicionLibro << std::endl;

    std::string tituloLibroMasVendido = obtenerTituloLibroMasVendido(libros, ventas);
    std::cout << "Título del libro más vendido: " << tituloLibroMasVendido << std::endl;

    std::string tituloLibroMasDinero = obtenerTituloLibroMasDinero(libros, ventas);
    std::cout << "Título del libro que más dinero ha recaudado: " << tituloLibroMasDinero << std::endl;

    int codigoClienteBuscado = 1;
    std::vector<std::string> titulosLibrosCliente = obtenerTitulosLibrosPorCliente(libros, ventas, codigoClienteBuscado);
    std::cout << "Títulos de libros comprados por el cliente con código " << codigoClienteBuscado << ": ";
    for (const auto& titulo : titulosLibrosCliente) {
        std::cout << titulo << " ";
    }
    std::cout << std::endl;

    std::string clienteMasCompras = obtenerClienteMasCompras(clientes, ventas);
    std::cout << "Cliente con más compras: " << clienteMasCompras << std::endl;

    std::string clienteMasDinero = obtenerClienteMasDinero(clientes, libros, ventas);
    std::cout << "Cliente que ha gastado más dinero: " << clienteMasDinero << std::endl;

    return 0;
}
