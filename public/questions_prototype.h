/*******************************************************************************
 *
 *      @file: questions_prototype.h
 *      @brief: 问答活动题库配置.
 *
 *      @author: gxl.
 *      @Date: 2013/01/27
 *      COPYRIGHT (C) 2012, KingNet INC., ALL RIGHT RESERVED.
 ******************************************************************************/

#ifndef QUESTIONS_PROTOTYPE_H
#define QUESTIONS_PROTOTYPE_H

#include <map>
#include <string>
#include <deque>
#include <vector>
#include "singleton.h"
#include "questions.pb.h"

class QuestionPrototype
{
public:
	bool init_questions(const char* data_file);
	void clear();

	std::string get_answer_by_id(int id);
	const QuestionData* get_random_question();

	bool is_question_in_recent_list(int id);

private:
	typedef std::map<int, QuestionData>  QuestionMap;

	// 
	typedef std::vector<int>  QuestionIDs;

	QuestionMap      m_all_questions;
	QuestionIDs      m_question_ids;

	std::deque<int>    m_latest_questions; // 最近抽中的10道题，防止短期内重复

	DECLARE_SINGLETON_CONSTRUCTER(QuestionPrototype);
};

#define QUESTIONS_INSTANCE Singleton<QuestionPrototype>::instance()

#endif




