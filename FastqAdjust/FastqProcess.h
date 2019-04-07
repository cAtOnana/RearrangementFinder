#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include<map>
#include<unordered_map>
class Fastq
{
  private:
    std::string info;
    std::string seq;
    std::string qua;

  public:
    struct DNA;
    struct RNA;
    //initialize
    Fastq(std::string f = "");
    Fastq(const char *f);
    //modified
    Fastq split_tail(int site);
    Fastq split_head(int site);
    bool quality_control(int threshold_value, DNA);
    Fastq quality_control(int threshold_value, RNA);
    Fastq split_adaptor(std::string adaptor_seq);
    //input/output
    friend std::istream &operator>>(std::istream &in, Fastq& fastq);
    friend std::ostream &operator<<(std::ostream &out, Fastq& fastq);
    //viewer
    std::string sequence();
    std::string quality();
    std::string seq_info();
};

class Fastq_vector : public std::vector<Fastq>
{
  public:
    //modified
    //input/output
    friend std::istream &operator>>(std::istream &in, Fastq_vector& fv);
    friend std::ostream &operator<<(std::ostream &out, Fastq_vector& fv);
};

template<typename container>
class Fastq_keycontainer :public container<Fastq>
{
public:
    //input/output
    friend std::istream &operator>>(std::istream &in, Fastq_keycontainer &fm);
    friend std::ostream &operator<<(std::ostream &out, Fastq_keycontainer &fm);
};