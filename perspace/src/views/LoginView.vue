<template>
    <ContentBase>
        <div class="register-page">
            <div class="register-container">
                <h2>登录</h2>
                <form @submit.prevent="login">
                    <div class="form-group">
                        <input
                            type="text"
                            v-model="username"
                            placeholder="用户名"
                            required
                        />
                    </div>

                    <div class="form-group">
                        <input
                            type="password"
                            v-model="password"
                            placeholder="密码"
                            required
                        />
                    </div>
                    <div class="error-message">{{ error_message }}</div>
                    <button @click="login" type="submit">登录</button>
                </form>
                <div class="form-footer">
                    <span>还没有账号？</span>
                    <router-link :to="{ name: 'register_index' }"
                        >注册</router-link
                    >
                </div>
            </div>
        </div>
    </ContentBase>
</template>

<script>
import { ref } from "vue";
import ContentBase from "../components/ContentBase.vue";
import { useStore } from "vuex";
import router from "@/router/index";
export default {
    name: "LoginView",
    components: {
        ContentBase,
    },
    setup() {
        let username = ref("");
        let password = ref("");
        let error_message = ref("");
        let store = useStore();
        const login = () => {
            store.dispatch("login", {
                username: username.value,
                password: password.value,
                success: () => {
                    router.push({
                        name: "userlist_index",
                    })
                },
                error: () => {
                    error_message.value = "用户名或密码错误";
                },
            });
        };

        return {
            username,
            password,
            error_message,
            login,
        };
    },
};
</script>

<style scoped>
.register-page {
    display: flex;
    justify-content: center;
    align-items: center;
    height: 50vh;
}

.register-container {
    width: 350px;
    padding: 40px;
    border-radius: 10px;
    background-color: #fff;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
}

h2 {
    margin-bottom: 20px;
    text-align: center;
    font-size: 24px;
    color: #333;
}

.form-group {
    margin-bottom: 20px;
}

input[type="text"],
input[type="email"],
input[type="password"] {
    width: 100%;
    padding: 12px;
    border: none;
    border-radius: 5px;
    background-color: #f5f5f5;
    box-sizing: border-box;
    outline: none;
}

button {
    width: 100%;
    padding: 12px;
    background-color: #007bff;
    color: #fff;
    border: none;
    border-radius: 5px;
    cursor: pointer;
    outline: none;
    transition: background-color 0.3s ease;
}

button:hover {
    background-color: #0056b3;
}

.form-footer {
    text-align: center;
}

.form-footer span {
    margin-right: 5px;
    color: #666;
}

.form-footer a {
    color: #007bff;
    text-decoration: none;
}

.form-footer a:hover {
    text-decoration: underline;
    color: #0056b3;
}

.error-message {
    color: red;
}
</style>
