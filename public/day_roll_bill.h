/*
 * day_roll_bill.h
 *
 *  Created on: 2011-10-19
 *      Author: lxyfirst@yahoo.com.cn
 */

#ifndef DAY_ROLL_BILL_H_
#define DAY_ROLL_BILL_H_

#include <time.h>

//class FightStatData; 

class day_roll_bill
{
public:
    enum
    {
        MAX_PREFIX_SIZE = 1024 ,
        MAX_LINE_SIZE = 4096 ,
    };

    enum
    {
        NONE_IOBUF_SIZE = 0 ,
        MIN_IOBUF_SIZE = MAX_LINE_SIZE ,
        MAX_IOBUF_SIZE = MAX_LINE_SIZE * 1000 ,
    };
public:
    int init(const char* prefix,int buf_size = NONE_IOBUF_SIZE) ;

    /*
     * @brief clean up
     */
    void fini() ;

    /*
     * @brief write formatted log data
     * @param [in] log level
     * @param [in] format string
     * @param [in] data
     */

    int write_sql(int seq,int result,const char* sql);


    int write_transaction() ;

	int write_trade(int seq, int role_id, int action_type, int trans_type, int money_type, int cost_value);

	/*
     * @brief write formatted money change log data
	 * @param [in] seq [sequence no.]
     * @param [in] role_id 
     * @param [in] action_type
     * @param [in] item_change_type [type defined in game_server.proto, how the item changed]
	 * @param [in] item_id
	 * @param [in] count
	 * @return : 0 on success, -1 on failure
     */
    int write_item(int seq, int role_id, int action_type, int item_change_type, int64_t item_id, int count) ;

	/*
     * @brief write formatted money change log data
	 * @param [in] seq [sequence no.]
     * @param [in] role_id 
     * @param [in] action_type
     * @param [in] change_money_type [type defined in game_server.proto, how the money changed]
	 * @param [in] money_type (MT_DIAMOND, MT_COIN, MT_COUPON)
	 * @param [in] money_value
	 * @param [in] result_money_value [ after change, money result value]
	 * @return : 0 on success, -1 on failure
     */
    int write_money(int seq, int role_id, int action_type, int change_money_type, int money_type, int money_value, int result_money_value);

	
protected:
    int write_format(const char* fmt,...) ;
    

    /*
     * @brief flush buffered data to disk
     */
    int flush() ;

    const char* get_prefix() { return m_prefix ; } ;

public:
    day_roll_bill();
    ~day_roll_bill();

private:
    day_roll_bill(const day_roll_bill& ) ;
    day_roll_bill& operator=(const day_roll_bill&) ;

private:

    typedef struct
    {
        int size ;
        int pos ;
        char data[0] ;
    } memory_buffer ;

protected:
    int prepare() ;

protected:
    int m_fd ;
    int m_filedate ;
    short m_level ;
    short m_delay ;
    memory_buffer* m_buf ;
    char m_prefix[MAX_PREFIX_SIZE] ;
    struct tm m_now ;


};

#endif /* DAY_ROLL_BILL_H_ */
