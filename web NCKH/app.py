from flask import Flask, render_template, request

app = Flask(__name__)


# ==========================================
# DỮ LIỆU TÀI LIỆU DEMO
# ==========================================

documents = [
    {
        "keywords": ["rag"],
        "answer": "RAG là viết tắt của Retrieval-Augmented Generation. Đây là phương pháp kết hợp việc tìm kiếm thông tin từ tài liệu với mô hình ngôn ngữ để tạo ra câu trả lời dựa trên dữ liệu được truy xuất."
    },

    {
        "keywords": ["python"],
        "answer": "Python là một ngôn ngữ lập trình có cú pháp đơn giản và dễ học. Python được sử dụng trong phát triển web, trí tuệ nhân tạo, Machine Learning và phân tích dữ liệu."
    },

    {
        "keywords": ["flask"],
        "answer": "Flask là một web framework của Python. Flask thường được sử dụng để xây dựng backend, website và API."
    },

    {
        "keywords": ["html"],
        "answer": "HTML là ngôn ngữ dùng để xây dựng cấu trúc của một trang web. HTML xác định các thành phần như tiêu đề, đoạn văn, hình ảnh, nút và biểu mẫu."
    },

    {
        "keywords": ["css"],
        "answer": "CSS được sử dụng để thiết kế giao diện website. CSS có thể thay đổi màu sắc, kích thước, vị trí, khoảng cách và bố cục của các thành phần HTML."
    },

    {
        "keywords": ["sql server"],
        "answer": "SQL Server là hệ quản trị cơ sở dữ liệu của Microsoft, được sử dụng để lưu trữ và quản lý dữ liệu của ứng dụng."
    }
]


# ==========================================
# HÀM RAG DEMO
# ==========================================

def rag_answer(question):

    question = question.lower()

    # Tìm tài liệu phù hợp
    for document in documents:

        for keyword in document["keywords"]:

            if keyword in question:

                return document["answer"]

    # Không tìm thấy tài liệu
    return (
        "Xin lỗi, hệ thống chưa tìm thấy thông tin "
        "phù hợp trong dữ liệu hiện tại."
    )


# ==========================================
# TRANG NHẬP
# ==========================================

@app.route("/")
def home():

    return render_template("input.html")


# ==========================================
# XỬ LÝ CÂU HỎI
# ==========================================

@app.route("/ask", methods=["POST"])
def ask():

    question = request.form.get("question", "")

    # Gọi RAG
    answer = rag_answer(question)

    # Chuyển sang trang kết quả
    return render_template(
        "output.html",
        question=question,
        answer=answer
    )


# ==========================================
# CHẠY WEBSITE
# ==========================================

if __name__ == "__main__":

    app.run(
        debug=True
    )