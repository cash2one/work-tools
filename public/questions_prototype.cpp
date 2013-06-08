/*******************************************************************************
 *
 *      @file: questions_prototype.cpp
 *      @brief: 问答活动题库配置.
 *
 *      @author: gxl.
 *      @Date: 2013/01/27
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#include <fstream>
#include <algorithm>
#include "questions_prototype.h"
#include <algorithm>

using namespace std;


bool QuestionPrototype::init_questions(const char* data_file)
{
	std::fstream  fs( data_file, std::ios::in | std::ios::binary );
	if (fs.fail()) return false ;

	QuestionDataGroup data_group_;

	if (!data_group_.ParseFromIstream(&fs))
	{
		return false;
	}

	clear();
	for (int i=0; i<data_group_.question_size(); ++i)
	{
		const QuestionData& d = data_group_.question(i);
		if (d.id() >= 0)
		{
			m_all_questions[d.id()] = d ; 
			m_question_ids.push_back(d.id());
		}
	}

	return true;
}

void QuestionPrototype::clear()
{
	m_question_ids.clear();
	m_all_questions.clear();
	m_latest_questions.clear();
}

string QuestionPrototype::get_answer_by_id(int id)
{	
	if (m_all_questions.count(id))
	{
		return m_all_questions[id].answer();
	}

	return "";
}

bool QuestionPrototype::is_question_in_recent_list(int id)
{
	return (find(m_latest_questions.begin(), m_latest_questions.end(), id) != m_latest_questions.end());
}


const QuestionData* QuestionPrototype::get_random_question()
{
	if (m_all_questions.size() <= 0 || m_question_ids.size() <= 0) return NULL;
	
	if (m_all_questions.size() != m_question_ids.size()) return NULL;
	
	int index = random() % m_question_ids.size();

	int i = 0;
	while(is_question_in_recent_list(index)
		&& i < 20)
	{
		index = random() % m_question_ids.size();
		i++;
	}

	if (m_latest_questions.size() > 10)
	{
		m_latest_questions.pop_front();
	}
	m_latest_questions.push_back(index);

	int id = m_question_ids[index];
	
	if (m_all_questions.count(id))
	{
		return  &m_all_questions[id];
	}
	
	return NULL;
}

