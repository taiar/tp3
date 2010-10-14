FILE = tp3

LATEX_EXECUTABLE=latex
LATEX_VISUALIZATION=evince
LATEX_EXTENSION=ps

all: ${FILE}.tex
	make clean
	${LATEX_EXECUTABLE} ${FILE}.tex
	make clean
	pdflatex ${FILE}.tex
clean:
	rm -f *.log *.aux *.bbl *.blg *.dvi *.lot *.toc *.lof *.out *~ 

see: all
	${LATEX_VISUALIZATION} ${FILE}.pdf &

run: see
