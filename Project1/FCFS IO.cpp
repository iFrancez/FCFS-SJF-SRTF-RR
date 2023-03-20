//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//struct Process {
//    int pid; // Process ID
//    int arrival_time; // Arrival time
//    int burst_time; // Burst time
//    int io_time; // I/O time
//    int io_duration; // I/O duration
//};
//
//int main() {
//    int n; // Số lượng tiến trình
//    cout << "Nhap so luong tien trinh: ";
//    cin >> n;
//
//    // Tạo một hàng đợi lưu trữ các tiến trình
//    queue<Process> process_queue;
//
//    // Nhập thông tin cho các tiến trình
//    for (int i = 0; i < n; i++) {
//        Process p;
//        cout << "Nhap thong tin tien trinh " << i + 1 << ":\n";
//        cout << "Nhap arrival time: ";
//        cin >> p.arrival_time;
//        cout << "Nhap burst time: ";
//        cin >> p.burst_time;
//        cout << "Nhap I/O time: ";
//        cin >> p.io_time;
//        cout << "Nhap I/O duration: ";
//        cin >> p.io_duration;
//        p.pid = i + 1;
//        process_queue.push(p);
//    }
//
//    int current_time = 0;  // Thời điểm hiện tại
//    int total_waiting_time = 0;  // Tổng thời gian chờ đợi của các tiến trình
//    queue<Process> io_queue;  // Hàng đợi I/O
//
//    // Xử lý các tiến trình
//    while (!process_queue.empty() || !io_queue.empty()) {
//        // Nếu hàng đợi tiến trình sẵn sàng rỗng
//        if (process_queue.empty()) {
//            current_time++;
//            continue;
//        }
//
//        // Lấy tiến trình đầu tiên từ hàng đợi tiến trình sẵn sàng để thực hiện
//        Process current_process = process_queue.front();
//        process_queue.pop();
//
//        // Nếu tiến trình đã đến thời điểm thực hiện
//        if (current_time >= current_process.arrival_time) {
//            // Thực hiện I/O
//            if (current_time == current_process.io_time) {
//                io_queue.push(current_process);
//            }
//            // Hoàn tất I/O, đưa tiến trình vào hàng đợi
//            else if (current_time == current_process.io_time + current_process.io_duration) {
//                current_process.io_time = -1; // Đánh dấu là tiến trình không còn thực hiện I/O nữa
//                current_process.arrival_time = current_time; // Cập nhật lại thời gian đến của tiến trình
//                process_queue.push(current_process);
//            }
//            // Thực hiện tiến trình
//            else {
//                current_process.burst_time--;
//                // Nếu tiến trình đã hoàn thành
//                if (current_process.burst_time == 0) {
//                    int waiting_time = current_time - current_process.arrival_time;
//                    total_waiting_time += waiting_time;
//                }
//                // Đưa tiến trình vào hàng đợi tiếp theo
//                else {
//                    process_queue.push(current_process);
//                }
//            }
//        }
//        // Tiến trình chưa đến
//    // Xử lý I/O
//        if (!io_queue.empty()) {
//            Process io_process = io_queue.front();
//            io_queue.pop();
//            io_process.io_duration--;
//            // Nếu I/O hoàn tất
//            if (io_process.io_duration == 0) {
//                io_process.io_time = -1; // Đánh dấu là tiến trình không còn thực hiện I/O nữa
//                io_process.arrival_time = current_time; // Cập nhật lại thời gian đến của tiến trình
//                process_queue.push(io_process);
//            }
//            // Nếu I/O chưa hoàn tất
//            else {
//                io_queue.push(io_process);
//            }
//        }
//
//        current_time++;
//    }
//
//    // Tính thời gian trung bình chờ đợi của mỗi tiến trình
//    float avg_waiting_time = (float)total_waiting_time / n;
//    cout << "Thoi gian trung binh cho doi cua moi tien trinh: " << avg_waiting_time << endl;
//
//    return 0;
//}