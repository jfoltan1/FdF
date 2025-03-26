# FDF - Wireframe Landscape Renderer

A simple 3D wireframe renderer written in C using **MiniLibX**. It takes a `.fdf` file containing heightmap data and turns it into a 3D isometric projection, rendered in a window.

---

## 🧠 What It Does

- Reads a `.fdf` file: a grid of altitude values.
- Plots a 3D landscape using line segments between points.
- Displays it using **MiniLibX** in isometric projection.
- Memory leak-free.

---

## ⚙️ How to Run

```bash
make
./fdf map.fdf
```

Press `ESC` or close the window to exit cleanly.

---

## 📦 Features

- ✅ Parses valid `.fdf` files with altitude data
- ✅ Displays the 3D model in isometric view
- ✅ Uses only allowed system + MLX functions
- ✅ Closes cleanly via window or ESC
- ✅ No memory leaks (valgrind clean)

---

## 🧰 Tech Stack

- Language: C (Norm compliant)
- Graphics: MiniLibX
- Build: `Makefile`
- Custom utils: `libft`, `ft_printf`, `get_next_line`

---

## 🏗️ Room for Improvements

- [ ] Add projection options (parallel/conic)
- [ ] Implement zoom and pan
- [ ] Add rotation support
- [ ] Improve error handling for malformed files
- [ ] Add interactive controls (keyboard/mouse)

---

## ⚠️ Known Limitations

- Assumes `.fdf` input is correctly formatted
- No GUI or menu overlays
- Only basic isometric rendering supported
- Not optimized for large maps

---

## 📁 Example `.fdf` File

```
0 0 0 0
0 10 10 0
0 0 0 0
```

Each number = elevation. Horizontal = X, vertical = Y, value = Z.


---
