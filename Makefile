# SHELL := /bin/bash



all:
	
	bash -c 'rm -rf -v !\(Makefile|html\)'
	
	mv html/* ./
	
	rm -rf html

	