FILE = tp3

LATEX_EXECUTABLE=latex
LATEX_VISUALIZATION=evince
LATEX_EXTENSION=ps

all: ${FILE}.tex
	make clean
	${LATEX_EXECUTABLE} ${FILE}.tex
	${LATEX_EXECUTABLE} ${FILE}.tex
	bibtex ${FILE}
	${LATEX_EXECUTABLE} ${FILE}.tex
	${LATEX_EXECUTABLE} ${FILE}.tex
	dvips -Pcmz ${FILE}.dvi
	dvips -Pcmz ${FILE}.dvi
	make clean
	ps2pdf ${FILE}.${LATEX_EXTENSION}
clean:
	rm -f *.log *.aux *.bbl *.blg *.dvi *.lot *.toc *.lof *.out *~ 

see: all
	${LATEX_VISUALIZATION} ${FILE}.${LATEX_EXTENSION} &

